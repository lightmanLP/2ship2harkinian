#include "Mouse.h"

#include "Context.h"

static MouseCoords current;

#ifdef __cplusplus
extern "C" {
#endif

void Mouse_Update() {
    Ship::Coords coords = Ship::Context::GetInstance()->GetWindow()->GetMouseDelta();
    current.x = coords.x;
    current.y = coords.y;
    SPDLOG_INFO("COORDS: {} {}", current.x, current.y);
}

MouseCoords Mouse_GetDelta() {
    return current;
}

MouseCoords Mouse_GetPos() {
    Ship::Coords coords = Ship::Context::GetInstance()->GetWindow()->GetMousePos();
    return { coords.x, coords.y };
}

void Mouse_SetCursorPos(s32 x, s32 y) {
    Ship::Context::GetInstance()->GetWindow()->SetMousePos({ x, y });
}

bool Mouse_IsCaptured() {
    return true;
    return Ship::Context::GetInstance()->GetWindow()->IsMouseCaptured();
}

#ifdef __cplusplus
} // extern "C"
#endif
