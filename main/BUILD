cc_library(
    name = "hello-greet",
    srcs = ["hello-greet.cpp"],
    hdrs = ["hello-greet.h"],
    deps = [
			"@boost//:log",
            "//proto:hey_cc_grpc",
            "@com_github_grpc_grpc//:grpc++",
    ],
    visibility = ["//test:__pkg__"],
)

cc_binary(
    name = "hello-world",
    srcs = ["main.cpp"],
    deps = [
        ":hello-greet",
    ],
)
