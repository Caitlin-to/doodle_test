//
// Created by Caitlin To on 10/12/2024.
//

#ifndef DOODLEJUMP_SETTINGS_H
#define DOODLEJUMP_SETTINGS_H

#endif //DOODLEJUMP_SETTINGS_H
#pragma once // to prevent multiple inclusions

#include <string>

namespace settings {
    const unsigned int resolutionWidth = 600;
    const unsigned int resolutionHeight = 800;
    const std::string gameName = "Doodle Jump";
    const unsigned int FPS = 60;

    const bool showHitboxesByDefault = false;
    const bool showFPSByDefault = false;
    const bool enableMusicbyDefault = true;
}