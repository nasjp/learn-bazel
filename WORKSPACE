workspace(name = "Demo")

# Prepare
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Proto
# https://github.com/bazelbuild/rules_proto
http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

# gRPC
# https://github.com/grpc/grpc
http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "9647220c699cea4dafa92ec0917c25c7812be51a18143af047e20f3fb05adddc",
    strip_prefix = "grpc-1.43.0",
    urls = [
        "https://github.com/grpc/grpc/archive/v1.43.0.tar.gz",
    ],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

# Google Test
# https://github.com/google/googletest
http_archive(
    name = "com_google_googletest",
    sha256 = "353571c2440176ded91c2de6d6cd88ddd41401d14692ec1f99e35d013feda55a",
    strip_prefix = "googletest-release-1.11.0",
    urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip"],
)

# Boost
# https://github.com/nelhage/rules_boost
_RULES_BOOST_COMMIT = "685557254da7ee57afc1204189b58253972e16be"

http_archive(
    name = "com_github_nelhage_rules_boost",
    sha256 = "11e436c3888f6c9583ea2e0beabb12167186b5c1d191722d191ea13a46a60c7a",
    strip_prefix = "rules_boost-%s" % _RULES_BOOST_COMMIT,
    urls = ["https://github.com/nelhage/rules_boost/archive/%s.tar.gz" % _RULES_BOOST_COMMIT],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()
