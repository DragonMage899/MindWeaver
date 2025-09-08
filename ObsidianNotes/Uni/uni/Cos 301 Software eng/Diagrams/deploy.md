```
@startuml
!theme cerulean

' Skin params for styling
skinparam rectangle {
  BackgroundColor<<User>> #A0D8EF
  BackgroundColor<<Dev>> #F9D423
  BackgroundColor<<Repo>> #FFE156
  BackgroundColor #FFF9C4
  BorderColor #333333
  RoundCorner 15
  FontName "Segoe UI"
  FontSize 14
  FontColor #222222
}

skinparam node {
  BackgroundColor<<DeploymentTarget>> #D0E6FF99
  BorderColor #1A237E
  RoundCorner 15
  FontName "Segoe UI"
  FontSize 14
  FontColor #1A237E
}

skinparam component {
  BackgroundColor #FFF9C4
  BorderColor #FBC02D
  RoundCorner 10
  FontName "Segoe UI"
  FontSize 13
  FontColor #4E342E
}

skinparam cloud {
  BackgroundColor #BBDEFB
  BorderColor #1976D2
  RoundCorner 20
  FontName "Segoe UI"
  FontSize 16
  FontColor #0D47A1
}

' Define rectangles with stereotypes for coloring
rectangle "User" as user <<User>>
rectangle "Developer" as dev <<Dev>>

node "GitHub" as github {
    rectangle "Repository (main branch)" as repo <<Repo>>
}

node "Cloud Environment" as cloud_env <<DeploymentTarget>> {
    
    node "Dedicated Server" as server {
        component "React Frontend (Port 3000)" as frontend
        component "JavaScript API (Port 3001)" as api
        component "Python Backend (Port 9011)" as backend
    }

    node "Docker Cloud" as docker_cloud {
        component "Docker Container Image" as docker_image
    }
    
    cloud "Internet" as internet
}

node "Local Environment" as local_env <<DeploymentTarget>> {
    component "Docker Container" as local_docker {
        component "React Frontend (Port 3000)" as local_frontend
        component "JavaScript API (Port 3001)" as local_api
        component "Python Backend (Port 9011)" as local_backend
    }
}

' Connections with styled arrows
user -[#1E88E5,bold]-> internet : "Accesses via Browser"
internet -[#1976D2,dashed]-> docker_cloud : "Routes to Docker Cloud container"
internet -[#0D47A1,dashed]-> server : "Routes to dedicated server"

server --[#43A047,bold] frontend : "Serves UI"
frontend -[#FB8C00]-> api : "API Calls"
api -[#F4511E]-> backend : "Backend Processing"
backend -[#F4511E,thickness=2]-> api : "Returns Data"
api -[#FB8C00,thickness=2]-> frontend : "Returns Data"

dev -[#FBC02D,bold]-> repo : "Push to main"
repo -[#FBC02D]-> github : "Triggers CI/CD"
github -[#1565C0,bold,dashed]-> server : "Deploy to Dedicated Server"
github -[#1565C0,bold,dashed]-> docker_cloud : "Build & Push Docker Container Image"

user -[#388E3C,bold]-> local_docker : "Runs local Docker container"
local_docker -[#81C784]-> local_frontend : "Accesses via port 3000"
local_frontend -[#FB8C00]-> local_api : "API Calls"
local_api -[#F4511E]-> local_backend : "Backend Processing"
local_backend -[#F4511E,thickness=2]-> local_api : "Returns Data"
local_api -[#FB8C00,thickness=2]-> local_frontend : "Returns Data"

docker_cloud -[#1565C0,dashed]-> local_docker : "Pulls container image"
@enduml
```

![[ATA_Deployment_4.png]]