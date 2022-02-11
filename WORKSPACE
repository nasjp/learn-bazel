workspace(name = "Demo")

# Prepare
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    ],
)

# C++ Bazel Rules
http_archive(
    name = "rules_cc",
    sha256 = "35f2fb4ea0b3e61ad64a369de284e4fbbdcdba71836a5555abb5e194cf119509",
    strip_prefix = "rules_cc-624b5d59dfb45672d4239422fa1e3de1822ee110",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_cc/archive/624b5d59dfb45672d4239422fa1e3de1822ee110.tar.gz",
        "https://github.com/bazelbuild/rules_cc/archive/624b5d59dfb45672d4239422fa1e3de1822ee110.tar.gz",
    ],
)

load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies")

rules_cc_dependencies()

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

# MySQL Connector/C++
# https://github.com/mysql/mysql-connector-cpp

new_local_repository(
    name = "libmysqlcppconn_linux",
    build_file = "//third_party:libmysqlcppconn_linux.BUILD",
    path = "/tmp/libmysqlcppconn/usr/",
)

http_archive(
    name = "libmysqlcppconn_windows",
    build_file = "//third_party:libmysqlcppconn_windows.BUILD",
    # sha256 = "11e436c3888f6c9583ea2e0beabb12167186b5c1d191722d191ea13a46a60c7a",
    strip_prefix = "mysql-connector-c++-8.0.28-winx64",
    urls = ["https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.28-winx64.zip"],
)
