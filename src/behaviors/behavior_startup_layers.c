/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_startup_layers

#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zephyr/logging/log.h>

#include <zmk/behavior.h>
#include <zmk/keymap.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int behavior_startup_layers_init(const struct device *dev) { 
    int32_t list[] = DT_INST_PROP(0, startup_layers_list);
    for (int32_t i = 0; i < DT_INST_PROP_LEN(0, startup_layers_list); i++) {
        LOG_DBG("behaviour_startup_layers activating layer %d", list[i]);
        zmk_keymap_layer_activate(list[i]);
    }

    return 0;
};

static const struct behavior_driver_api behavior_startup_layers_api = {
};

BEHAVIOR_DT_INST_DEFINE(0, behavior_startup_layers_init, NULL, NULL, NULL,
                        POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &behavior_startup_layers_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
