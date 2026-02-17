#pragma once

//config for static variables in case for positioning smth etc.

static const float WIDTH = 1280;
static const float HEIGHT = 720; 

static const float TILE_SIZE = 113;
//bar edge || interact zone with customers
// 113 - 1 tile * 3 tiles
static const float INTERACT_ZONE_X = TILE_SIZE * 3;
static const float INTERACT_ZONE_Y = TILE_SIZE * 2;

static const float ENTRANCE_ZONE_X = TILE_SIZE * 8;
static const float ENTRANCE_ZONE_Y = TILE_SIZE * 2;

static const float DIALOGUE_BOX_X = TILE_SIZE * 0;
static const float DIALOGUE_BOX_Y = TILE_SIZE * 4;