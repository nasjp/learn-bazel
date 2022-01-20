package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "hey_proto",
    srcs = [":hey.proto"],
)

cc_proto_library(
    name = "hey_cc_proto",
    deps = [":hey_proto"],
)

cc_grpc_library(
    name = "hey_cc_grpc",
    srcs = [":hey_proto"],
    grpc_only = True,
    deps = [":hey_cc_proto"],
)
