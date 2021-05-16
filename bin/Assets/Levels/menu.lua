HowManyGameObjects = 3

go_0 = {}
go_0[0] = { Name = "Camera", HowManyCmps = 2, Persist = false}
go_0[1] = { Component = "Transform"}
go_0[2] = { Component = "Camera", Plane = {Near = 0.01},
			Compositors = {"JugadorVisionWeak", false, "JugadorVisionStrong", false, "JugadorVisionInjured", false}, SlaveRotation=false}

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
