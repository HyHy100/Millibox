#pragma once
#include<map>
#include<string>
#include<memory>
#include"Workspace.h"

class WorkspaceManager {
	Workspace* currentWorkspace_;
	std::map<std::string, std::unique_ptr<Workspace>> workspaces_;
public:
	decltype(workspaces_)& getAllWorkspaces();
	Workspace& createWorkspace(std::string file);
	void setWorkspace(Workspace& workspace);
	Workspace& getWorkspace();
};