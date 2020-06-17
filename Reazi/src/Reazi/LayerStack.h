#pragma once

#include "Reazi/Core.h"
#include "Layer.h"

#include <vector>

namespace Reazi
{

	class REAZI_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void popLayer(Layer* layer);

		void pushOverlay(Layer* overlay);
		void popOverlay(Layer* overlay);

		inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<Layer*> m_layers;
		std::vector<Layer*>::iterator m_layersInsert;
	};

}