#pragma once

#include "rzpch.h"

#include "Reazi/Core.h"
#include "Reazi/events/Event.h"

#include <string>

namespace Reazi
{

	class REAZI_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& e) {}

		inline const std::string& getName() { return m_debugName; }
	protected:
		std::string m_debugName;
	};

}