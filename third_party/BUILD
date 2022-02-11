package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libmysqlcppconn",
    deps = select({
        "@platforms//os:windows": ["@libmysqlcppconn_windows"],
        "//conditions:default": ["@libmysqlcppconn_linux"],
    }),
)
