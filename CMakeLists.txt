cmake_minimum_required(VERSION 3.10)
project(DoodleJump VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

set(SOURCE_FILES
        src/main.cpp
        src/game/Game.h
        src/game/Game.cpp
        src/entities/Player.h
        src/entities/Player.cpp
        src/utils/Stopwatch.h
        src/utils/Stopwatch.cpp
        src/view/PlayerView.h
        src/view/PlayerView.cpp
        src/game/GameController.h
        src/game/GameController.cpp
        src/world/World.h
        src/world/World.cpp
        src/utils/Random.h
        src/utils/Random.cpp
        src/entities/Tile.h
        src/entities/Tile.cpp
        src/utils/Helpers.h
        src/utils/Helpers.cpp
        src/factory/ConcreteFactory.h
        src/factory/ConcreteFactory.cpp
        src/factory/AbstractFactory.h
        src/factory/AbstractFactory.cpp
        src/Settings.h
        src/view/TileView.h
        src/view/TileView.cpp
        src/camera/Camera.h
        src/camera/Camera.cpp
        src/entities/HorizontalTile.cpp
        src/entities/StaticTile.cpp
        src/entities/TemporaryTile.cpp
        src/entities/VerticalTile.cpp
        src/utils/ScoreTracker.h
        src/utils/ScoreTracker.cpp
        src/utils/ScoreDisplay.h
        src/utils/ScoreDisplay.cpp
        src/entities/bonus/Spring.h
        src/entities/bonus/Spring.cpp
        src/view/bonusView/SpringView.h
        src/view/bonusView/SpringView.cpp
        src/entities/bonus/Jetpack.h
        src/entities/bonus/Jetpack.cpp
        src/view/bonusView/JetpackView.h
        src/view/bonusView/JetpackView.cpp
)

add_executable(DoodleJump ${SOURCE_FILES})

target_link_libraries(DoodleJump sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(DoodleJump PRIVATE src)

install(TARGETS DoodleJump DESTINATION bin)