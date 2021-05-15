HowManyGameObjects = 1


go_0 = {}
go_0[0] = { Name = "UIManager", HowManyCmps = 3, Persist = false}
go_0[1] = { Component = "Transform"}
go_0[2] = { Component = "Camera", Plane = {Near = 0.01},
			Compositors = {"JugadorVisionWeak", false, "JugadorVisionStrong", false, "JugadorVisionInjured", false}, SlaveRotation=false}
go_0[3] = { Component = "ButtonComponent", Active = true, OverLayName="MenuUI", ContainerName= "Menu/PlayButton", 
			DefaultMaterial = "keyMaterial", HoverMaterial = "keyMaterial", PressMaterial = "keyMaterial"}
