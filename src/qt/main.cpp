// Copyright (c) 2018 The Bitcoin Core developers
// Copyright (c) 2020-2023 The Raptoreum developers
// Copyright (c) 2024-2025 The SnowPuppyCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://opensource.org/licenses/mit-license.php

#include <qt/snowpuppycoin.h>

#include <QCoreApplication>

#include <functional>
#include <string>

/** Translate string to current locale using Qt. */
extern const std::function<std::string(const char *)> G_TRANSLATION_FUN = [](const char *psz) {
    return QCoreApplication::translate("snowpuppycoin-core", psz).toStdString();
};

int main(int argc, char *argv[]) { return GuiMain(argc, argv); }
