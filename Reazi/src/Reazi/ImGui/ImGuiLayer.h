#pragma once

#include "Reazi/Layer.h"

namespace Reazi
{

	class REAZI_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onUpdate() override;
		virtual void onEvent(Event& e) override;

	private:

		float m_time = 0.f;
	};

}