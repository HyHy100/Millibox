#include"WorkspaceManager.h"

Workspace& WorkspaceManager::createWorkspace(std::string name) {
	printf("beggining workspace c\n");
	Workspace* workspace = new Workspace();
	printf("bce\n");
	workspaces_.insert(workspaces_.end(), { name, std::unique_ptr<Workspace>(workspace) });
	return *workspace;
}

void WorkspaceManager::setWorkspace(Workspace& workspace) {
	printf("bce\n");
	currentWorkspace_ = &workspace;
	printf("bce\n");
}

decltype(WorkspaceManager::workspaces_)& WorkspaceManager::getAllWorkspaces() {
	return workspaces_;
}

Workspace& WorkspaceManager::getWorkspace() {
	return *currentWorkspace_;
}