#include "stdafx.h"
#include "FrameList.h"

FrameList::FrameList()
{
}

FrameList::~FrameList()
{
}

void FrameList::update() {
	printf("updating framelist...\n");
	auto vsize = Application::get().getWindow().getSize();
	ImGui::Begin("Frames", 0, ImVec2(vsize.x, vsize.y));
	auto& workspaceManager = Application::get().getWorkspaceManager();
	if (workspaceManager.getAllWorkspaces().size() > 0) {
		auto& workspace = workspaceManager.getWorkspace();
		auto& frames = workspace.getCurrentAnimation().getFrameList();
		printf("updating framelist...........%d\n", frames.size());
		for (auto i = 0; i < frames.size() - 1; ++i) {
			ImGui::PushID(i);
			if (ImGui::Button(std::to_string(i).c_str(), ImVec2(60, 60))) {
				auto& res = Application::get().getWorkspaceManager().getWorkspace();
				res.getCurrentAnimation().setFrame(*res.getCurrentAnimation().getFrameList()[i]);
			}
			ImGui::PopID();
			ImGui::SameLine();
		}
	}
	printf("updating framelist..ffff.........\n");
	ImGui::End();

	printf("updating framelist..ffff.........\n");
}
void FrameList::render() {
}