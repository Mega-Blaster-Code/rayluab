local rayluab = require("rayluab")

rayluab.InitWindow(500, 500, 60, "this is a test")

rayluab.SetTargetFPS(70)

rayluab.SetWindowTitle("sdfsd")

local running = true

while running do
	if rayluab.IsKeyDown(65) then
		running = false
	end

    rayluab.BeginDrawing()
    rayluab.ClearBackground(0, math.floor((math.sin(rayluab.GetTime() * 10) + 1) / 2 * 255), 255, 255)
    rayluab.EndDrawing()

	running = running and not rayluab.WindowShouldClose()
end

rayluab.CloseWindow()

print("rayluab!")
