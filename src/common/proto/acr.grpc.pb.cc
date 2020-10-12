// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: acr.proto

#include "acr.pb.h"
#include "acr.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace lacr {

static const char* Classify_method_names[] = {
  "/lacr.Classify/Recognise",
};

std::unique_ptr< Classify::Stub> Classify::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Classify::Stub> stub(new Classify::Stub(channel));
  return stub;
}

Classify::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Recognise_(Classify_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Classify::Stub::Recognise(::grpc::ClientContext* context, const ::lacr::Request& request, ::lacr::Response* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Recognise_, context, request, response);
}

void Classify::Stub::experimental_async::Recognise(::grpc::ClientContext* context, const ::lacr::Request* request, ::lacr::Response* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Recognise_, context, request, response, std::move(f));
}

void Classify::Stub::experimental_async::Recognise(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::lacr::Response* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Recognise_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::lacr::Response>* Classify::Stub::AsyncRecogniseRaw(::grpc::ClientContext* context, const ::lacr::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::lacr::Response>::Create(channel_.get(), cq, rpcmethod_Recognise_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::lacr::Response>* Classify::Stub::PrepareAsyncRecogniseRaw(::grpc::ClientContext* context, const ::lacr::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::lacr::Response>::Create(channel_.get(), cq, rpcmethod_Recognise_, context, request, false);
}

Classify::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Classify_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Classify::Service, ::lacr::Request, ::lacr::Response>(
          std::mem_fn(&Classify::Service::Recognise), this)));
}

Classify::Service::~Service() {
}

::grpc::Status Classify::Service::Recognise(::grpc::ServerContext* context, const ::lacr::Request* request, ::lacr::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace lacr

