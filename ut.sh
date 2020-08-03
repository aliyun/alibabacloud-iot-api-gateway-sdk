#!/bin/bash

function upload_codecov_report {
  # upload_codecov_report <dir> <flag>
  cd "$1" || return 126
  wget --no-check-certificate https://codecov.io/bash -O codecov.sh
  pwd
  bash codecov.sh -cF "$2"
}

function run_php {
  cd php/ || return 126
  composer --version
  composer install -vvv
  composer test || return 126
  cd ../
  upload_codecov_report php php
}

function run_python {
  #env
  export PYTHONPATH=$PYTHONPATH:`pwd`/python
  echo $PYTHONPATH
  # install
  cd python || return 126
  pip install coverage
  pip install alibabacloud-tea-util
  pip install alibabacloud-apigateway-util

  coverage run --source="./alibabacloud_iot_api_gateway" -m pytest tests/test_* || return 126
  cd ../
  upload_codecov_report python python
}

function run_go {
  cd golang/ || return 126
  export GO111MODULE=on
  go mod tidy
  go test -race -coverprofile=coverage.txt -covermode=atomic ./client/... || return 126
  cd ../
  upload_codecov_report golang go
}

function run_csharp {
  # before_install
  wget https://download.visualstudio.microsoft.com/download/pr/42f39f2f-3f24-4340-8c57-0a3133620c21/0a353696275b00cbddc9f60069867cfc/dotnet-sdk-2.2.110-linux-x64.tar.gz
  mkdir -p ~/dotnet/ && tar zxf dotnet-sdk-2.2.110-linux-x64.tar.gz -C ~/dotnet/
  sudo ln -sf ~/dotnet/dotnet /usr/bin/dotnet
  dotnet --info

  # install
  cd csharp/tests/ || return 126
  dotnet tool install --global altcover.visualizer
  dotnet restore
  dotnet build
  cd ../

  # run tests
  dotnet test tests/ /p:AltCover=true || return 126
  cd ../

  # upload code coverage report
  upload_codecov_report csharp csharp
}

function contains {
  local value=$2
  for i in $1
  do
    if [ "$i" == "$value" ]; then
      echo "y"
      return 0
    fi
  done
  echo "n"
  return 1
}

function run_java {
  cd java/ || return 126
  mvn test -B || return 126
  cd ../
  upload_codecov_report java java
}

lang=$1

if [ "$lang" == "php" ]
then
  echo "run php"
  run_php
elif [ "$lang" == "java" ]
then
  echo "run java"
  run_java
elif [ "$lang" == "go" ]
then
  echo "run golang"
  run_go
elif [ "$lang" == "python" ]
then
  echo "run python"
  run_python
elif [ "$lang" == "csharp" ]
then
  echo "run csharp"
  run_csharp
fi

exit $?