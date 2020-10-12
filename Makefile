
target:
	export LD_LIBRARY_PATH=/caffe/caffe/build:/usr/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH
	sudo ldconfig
	g++ -g -std=c++11 -fpermissive -w \
                        src/classify/acr.cpp                   \
                        src/classify/classifier.cpp            \
                        src/main.cpp                           \
                        -o lacr                            \
                        -I src/classify                    \
                        -I /caffe/caffe/include            \
                        -I /usr/include                    \
                        -I /usr/local/include              \
                        -I /usr/local/cuda-8.0/include     \
                        -I /caffe/caffe/.build_release/src \
                        -L /usr/lib                        \
                        -L /usr/local/lib                  \
                        -L /caffe/caffe/build/lib          \
                        -L /usr/lib/x86_64-linux-gnu       \
                        -lcaffe                            \
                        -lboost_system                     \
                        -lglog                             \
                        -lpthread                          \
                        -lopencv_highgui                   \
                        -lopencv_core                      \
                        -lopencv_imgproc                   \
                        -lboost_system

.PHONY:proto
proto:
	protoc -I src/common/proto --cpp_out=src/common/proto/ acr.proto
	protoc -I src/common/proto --grpc_out=src/common/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` acr.proto
