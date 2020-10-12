CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(lacr_cloud_acr)

SET(CMAKE_CXX_STANDARD 14)
SET(TARGET_NAME lacr)

SET(CMAKE_C_FLAGS "-g")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/api/http)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/classify)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common/proto)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/option)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/config)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/utils/json)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/utils/crow)
INCLUDE_DIRECTORIES(/usr/include)
INCLUDE_DIRECTORIES(/caffe/caffe/include)
INCLUDE_DIRECTORIES(/usr/local/cuda-8.0/include)
INCLUDE_DIRECTORIES(/caffe/caffe/.build_release/src)
INCLUDE_DIRECTORIES(/usr/local/include)
INCLUDE_DIRECTORIES(/caffe/caffe/build/include)

LINK_LIBRARIES(/usr/lib)
LINK_DIRECTORIES(/caffe/caffe/build/lib)
LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu)


ADD_EXECUTABLE(${TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/classify/acr.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/classify/acr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/classify/classifier.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/classify/classifier.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/common/proto/acr.pb.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/common/proto/acr.pb.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/common/proto/acr.grpc.pb.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/common/proto/acr.grpc.pb.cc
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/rpc/classify_service.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/rpc/classify_service.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/rpc/service.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/rpc/service.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config/config.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config/config.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/option/option.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/option/option.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/http/server.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/api/http/classify_img.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log/log.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/log/log.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/json/json.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/crow/crow_all.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/crow/crow_body.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/encrypt/base64.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/encrypt/base64.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

TARGET_LINK_LIBRARIES(${TARGET_NAME} pthread
        opencv_highgui opencv_core opencv_imgproc
        boost_regex boost_filesystem boost_system caffe glog)

