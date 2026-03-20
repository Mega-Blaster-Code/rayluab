local inspect = require("C_inspect")

local rayluab = require("rayluab")

print(inspect(rayluab))

rayluab.Window.SetTraceLogLevel(rayluab.Window.Logs.LOG_NONE)

rayluab.Window.InitWindow(500, 500, "this is a test")

rayluab.Window.SetTargetFPS(70)

rayluab.Window.SetWindowTitle("sdfsd")

rayluab.Audio.InitAudioDevice()

local grace_music = rayluab.Audio.LoadSound("grace.mp3")
rayluab.Audio.PlaySound(grace_music)
local running = true

while running do
	local key = rayluab.Keyboard.GetKeyPressed()
	
    rayluab.Window.SetWindowTitle(tostring(rayluab.Window.GetFPS()))
	
    rayluab.Window.BeginDrawing()
    rayluab.Window.ClearBackground((math.sin(rayluab.Window.GetTime() * 10) + 1) / 2, 1, 0, 1)
	
    rayluab.Window.EndDrawing()
	
    running = running and not rayluab.Window.WindowShouldClose()
end

rayluab.Audio.UnloadSound(grace_music)

rayluab.Window.CloseWindow()

rayluab.Audio.CloseAudioDevice()

print("rayluab!")
