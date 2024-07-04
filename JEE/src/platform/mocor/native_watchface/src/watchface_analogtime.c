/*
 * Copyright (C) 2021 UNISOC Technologies Co.,Ltd. All Rights Reserved
 *
 * Automatically generated by code_generator_unirtos.pm.
*/

#include "sci_types.h"
#include "os_api.h"
#include "mmk_app.h"
#include "mmk_type.h"
#include "caf.h"
#include "ctrlbutton_export.h"
#include "guianim.h"
#include "ctrlbase.h"
#include "urjs_art.h"

#include "mmi_image.h"

#include "watchface_analogtime.h"

#include "watchface_ctrl_adapter.h"
 
uint32 js_native_watchface_analogtime_create(uint32 this_value, uint32 win_handle, double center_x, double center_y, char* hour, char* minute, char* second, int update_internal, double scale){
    WATCHFACE_RATIO_POSITION_T position = {0};
    WATCHFACE_CTRL_PARAM_T     ctrl_param = {0};
    position.ratio_x = center_x;
    position.ratio_y = center_y;
    char l_hour[MAX_PATH] = {0};
    char l_min[MAX_PATH] = {0};
    char l_sec[MAX_PATH] = {0};
    if (-1 == js_jee_get_native_path(hour, l_hour, sizeof(l_hour) - 1))
    {
        aloge("invalidate path: %s", hour);
        return -1;
    }
    if (-1 == js_jee_get_native_path(minute, l_min, sizeof(l_min) - 1))
    {
        aloge("invalidate path: %s", minute);
        return -1;
    }
    if (-1 == js_jee_get_native_path(second, l_sec, sizeof(l_sec) - 1))
    {
        aloge("invalidate path: %s", second);
        return -1;
    }

    ctrl_param.center_position.ratio_x = position.ratio_x;
    ctrl_param.center_position.ratio_y = position.ratio_y;
    ctrl_param.scale = scale;
    ctrl_param.update_interval = update_internal;
    ctrl_param.p_image_list[0] = l_hour;
    ctrl_param.p_image_list[1] = l_min;
    ctrl_param.p_image_list[2] = l_sec;
    return WATCHFACE_AnalogTime_Create(win_handle, &ctrl_param);
}

void js_native_watchface_analogtime_destory(uint32 handle){
    WATCHFACE_AnalogTime_Destory(handle);
}