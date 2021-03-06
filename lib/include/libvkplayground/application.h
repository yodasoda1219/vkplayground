#pragma once
#include "window.h"
#include "vulkan_object.h"
namespace libplayground {
    namespace vk {
        class application {
        public:
            application(const std::string& title, int32_t width, int32_t height);
            virtual ~application();
            void run();
        protected:
            virtual void load() = 0;
            virtual void update();
            virtual void render() = 0;
            virtual void unload() = 0;
        private:
            void init_vulkan();
            void main_loop();
            std::shared_ptr<window> m_window;
            std::string m_title;
            std::shared_ptr<vulkan_object> m_instance, m_debug_messenger, m_device, m_surface, m_swapchain;
            bool m_validation_layers_enabled;
        };
    }
}