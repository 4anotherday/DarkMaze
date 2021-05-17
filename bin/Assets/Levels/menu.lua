HowManyGameObjects = 4

go_0 = {}
go_0[0] = { Name = "Camera", HowManyCmps = 2, Persist = false}
go_0[1] = { Component = "Transform"}
go_0[2] = { Component = "Camera", Plane = {Near = 0.01}, SlaveRotation=false}
go_0[3] = { Component = "Listener", ListenerNumber = 0, Velocity = {X = 0, Y = 0, Z = 0} }

go_1 = {}
go_1[0] = { Name = "PlayButton", HowManyCmps = 3, Persist = false}
go_1[1] = { Component = "Transform"}
go_1[2] = { Component = "ButtonComponent", Active = true, OverLayName="MenuUI", ContainerName= "Menu/PlayButton", 
			DefaultMaterial = "keyMaterial", HoverMaterial = "keyMaterial", PressMaterial = "keyMaterial"}
go_1[3] = { Component = "PlayButtonComponent"}

go_2 = {}
go_2[0] = { Name = "QuitButton", HowManyCmps = 3, Persist = false}
go_2[1] = { Component = "Transform"}
go_2[2] = { Component = "ButtonComponent", Active = true, OverLayName="MenuUI", ContainerName= "Menu/QuitButton", 
			DefaultMaterial = "keyMaterial", HoverMaterial = "keyMaterial", PressMaterial = "keyMaterial"}
go_2[3] = { Component = "QuitButtonComponent"}

go_3 = {}
go_3[0] = { Name = "GameManager", HowManyCmps = 3, Persist = true}
go_3[1] = { Component = "Transform"}
go_3[2] = { Component = "GameManagerComponent", Level = 1, MaxLevel = 3}
go_3[3] = { Component = "AudioSource", Route = {"Assets/Audio/ProtoDarkMaze_Menu.mp3"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume = 0.1, Loop = -1, Stereo = false, Play = true}