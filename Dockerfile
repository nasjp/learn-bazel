FROM gcc:11.2.0

RUN apt-get update && apt-get install -y  \
	wget \
	build-essential

# Install bazelisk
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-linux-amd64 -O bazel
RUN chmod +x bazel
RUN mv bazel /usr/local/bin/bazel

# Install Buildifier
RUN wget https://github.com/bazelbuild/buildtools/releases/download/5.0.0/buildifier-linux-amd64 -O buildifier
RUN chmod +x buildifier
RUN mv buildifier /usr/local/bin/buildifier

# Install libmysqlcppconn
RUN wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn9_8.0.28-1debian11_amd64.deb
RUN wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn8-2_8.0.28-1debian11_amd64.deb
RUN wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn-dev_8.0.28-1debian11_amd64.deb
RUN dpkg -X libmysqlcppconn9_8.0.28-1debian11_amd64.deb /tmp/libmysqlcppconn
RUN dpkg -X libmysqlcppconn8-2_8.0.28-1debian11_amd64.deb /tmp/libmysqlcppconn
RUN dpkg -X libmysqlcppconn-dev_8.0.28-1debian11_amd64.deb /tmp/libmysqlcppconn

# Install bazel
WORKDIR /app
COPY .bazeliskrc .bazeliskrc
RUN bazel version
