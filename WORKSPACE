workspace(name = "BoostFilesystemDemo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# Boost
git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "685557254da7ee57afc1204189b58253972e16be",
    remote = "https://github.com/nelhage/rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

# Protocol Buffers
# http_archive(
#     name = "rules_proto",
#     sha256 = "73ebe9d15ba42401c785f9d0aeebccd73bd80bf6b8ac78f74996d31f2c0ad7a6",
#     strip_prefix = "rules_proto-2c0468366367d7ed97a1f702f9cd7155ab3f73c5",
#     urls = [
#         "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/2c0468366367d7ed97a1f702f9cd7155ab3f73c5.tar.gz",
#         "https://github.com/bazelbuild/rules_proto/archive/2c0468366367d7ed97a1f702f9cd7155ab3f73c5.tar.gz",
#     ],
# )
# load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
# rules_proto_dependencies()
# rules_proto_toolchains()

# http_archive(
#     name = "com_github_grpc_grpc",
#     sha256 = "2fcb7f1ab160d6fd3aaade64520be3e5446fc4c6fa7ba6581afdc4e26094bd81",

#     strip_prefix = "grpc-1.26.0",
#     urls = [
#         "https://github.com/grpc/grpc/archive/v1.26.0.tar.gz",
#         ],
# )
# load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
# grpc_deps()

# load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
# grpc_extra_deps()

# Google Test
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# http_archive(
#     name = "gtest",
#     url = "https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip",
#     sha256 = "353571c2440176ded91c2de6d6cd88ddd41401d14692ec1f99e35d013feda55a",
#     build_file = "@//:gtest.BUILD",
#     strip_prefix = "googletest-release-1.11.0",
# )

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip"],
  strip_prefix = "googletest-release-1.11.0",
  sha256 = "353571c2440176ded91c2de6d6cd88ddd41401d14692ec1f99e35d013feda55a",
)
