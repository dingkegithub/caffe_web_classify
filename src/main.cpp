//
// Created by dk on 12/11/19.
//
#include "acr.h"
#include "option.h"
#include "config.h"
#include "log.h"
#include "server.h"
#include <string>
#include <iostream>


int main(int argc, char **argv) {
    std::string config_file = parse_cmd_opt(argc, argv);
    cfg::config_t config = cfg::parse(config_file);
    log_init(argv[0], config.log.size, config.log.level, config.log.dir);

    acr::Acr::config(
            config.acr.model,
            config.acr.deploy,
            config.acr.mean,
            config.acr.word,
            config.acr.gpu_enable,
            config.acr.gpu_number);
    acr::Acr::instance();

    char address[30] = {0};
    sprintf(address, "0.0.0.0:%d", config.env.listen_port);

    LOG(INFO) << "Server start on: " << address << std::endl;
    http_server::run_server(config.env.listen_port);

    return 0;
}

