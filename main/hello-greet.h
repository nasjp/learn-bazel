#include <grpc++/grpc++.h>

#include <boost/log/trivial.hpp>
#include <string>

#include "proto/hey.grpc.pb.h"

std::string get_greet(std::string name);
