local inspect = require("C_inspect")

local rayluab = require("rayluab")

print(inspect(rayluab))

rayluab.Window.SetTraceLogLevel(rayluab.Window.Logs.LOG_NONE)

rayluab.Window.InitWindow(500, 500, "this is a test")

rayluab.Window.SetTargetFPS(70)

rayluab.Window.SetWindowTitle("sdfsd")

rayluab.Audio.InitAudioDevice()

local keys_sound = {rayluab.Audio.LoadSound("key1.mp3"), rayluab.Audio.LoadSound("key2.mp3"), rayluab.Audio.LoadSound("key3.mp3")}

local pause = false

local running = true

while running do
	local key = rayluab.Keyboard.GetKeyPressed()
	if key ~= rayluab.Keyboard.Keys.null and key > 32 and key < 128 then
		local f = math.random(1, #keys_sound)
		print(string.char(key))
		rayluab.Audio.PlaySound(keys_sound[f])
	end

    rayluab.Window.SetWindowTitle(tostring(rayluab.Window.GetFPS()))

    rayluab.Window.BeginDrawing()
    rayluab.Window.ClearBackground((math.sin(rayluab.Window.GetTime() * 10) + 1) / 2, 1, 0, 1)

    rayluab.Window.EndDrawing()

    running = running and not rayluab.Window.WindowShouldClose()
end

for i, v in ipairs(keys_sound) do
	rayluab.Audio.UnloadSound(v)
end

rayluab.Window.CloseWindow()

rayluab.Audio.CloseAudioDevice()

print("rayluab!")
