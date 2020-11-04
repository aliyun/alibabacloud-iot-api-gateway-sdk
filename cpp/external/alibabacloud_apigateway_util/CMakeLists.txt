find_package(alibabacloud_apigateway_util QUIET)

if(alibabacloud_apigateway_util_FOUND)
  message(STATUS "Found alibabacloud_apigateway_util version ${alibabacloud_apigateway_util_VERSION}")
else()
  message(STATUS "alibabacloud_apigateway_util could not be located, Building alibabacloud_apigateway_util instead.")
  include(FetchContent)

  FetchContent_Declare(
    _alibabacloud_apigateway_util
    GIT_REPOSITORY https://github.com/alibabacloud-sdk-cpp/apigateway-util.git
    GIT_TAG master
    CMAKE_ARGS
      -DENABLE_UNIT_TESTS:BOOL="0")

  FetchContent_GetProperties(_alibabacloud_apigateway_util)
  if(NOT _alibabacloud_apigateway_util_POPULATED)
    FetchContent_Populate(_alibabacloud_apigateway_util)
    message(STATUS "Added alibabacloud_apigateway_util source : ${_alibabacloud_apigateway_util_SOURCE_DIR}")
    message(STATUS "Added alibabacloud_apigateway_util binary : ${_alibabacloud_apigateway_util_BINARY_DIR}")
    add_subdirectory(
      ${_alibabacloud_apigateway_util_SOURCE_DIR}
      ${_alibabacloud_apigateway_util_BINARY_DIR}
    )
  endif()
  target_include_directories(alibabacloud_iot_api_gateway PRIVATE "${_alibabacloud_apigateway_util_SOURCE_DIR}/include")
  if(ENABLE_UNIT_TESTS)
    target_include_directories(tests_alibabacloud_iot_api_gateway PRIVATE "${_alibabacloud_apigateway_util_SOURCE_DIR}/include")
  endif()
endif()
