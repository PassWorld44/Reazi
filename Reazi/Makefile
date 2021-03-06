# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
PCH = src/rzpch.h
PCH_PLACEHOLDER = $(OBJDIR)/$(notdir $(PCH))
GCH = $(PCH_PLACEHOLDER).gch
INCLUDES += -Ivendor/spdlog/include -Isrc -Ivendor/GLFW/include -Ivendor/Glad/include -Ivendor/imgui
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef

ifeq ($(config),debug)
TARGETDIR = ../bin/Debug-windows-x86/Reazi
TARGET = $(TARGETDIR)/Reazi.dll
OBJDIR = ../bin-int/Debug-windows-x86/Reazi
DEFINES += -DRZ_PLATFORM_WINDOWS -DRZ_BUILD_DLL -D_WINDLL -DRZ_DEBUG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -g /MDd
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -g -std=c++17 /MDd
LIBS += vendor/GLFW/bin/Debug-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Debug-windows-x86/Glad/Glad.lib vendor/imgui/bin/Debug-windows-x86/ImGui/ImGui.lib -lopengl32.lib
LDDEPS += vendor/GLFW/bin/Debug-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Debug-windows-x86/Glad/Glad.lib vendor/imgui/bin/Debug-windows-x86/ImGui/ImGui.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -m32 -shared -Wl,--out-implib="../bin/Debug-windows-x86/Reazi/Reazi.lib"
define POSTBUILDCMDS
	@echo Running postbuild commands
	IF EXIST ..\bin\Debug-windows-x86\Reazi\Reazi.dll\ (xcopy /Q /E /Y /I ..\bin\Debug-windows-x86\Reazi\Reazi.dll ..\bin\Debug-windows-x86\Sandbox > nul) ELSE (xcopy /Q /Y /I ..\bin\Debug-windows-x86\Reazi\Reazi.dll ..\bin\Debug-windows-x86\Sandbox > nul)
endef

else ifeq ($(config),release)
TARGETDIR = ../bin/Release-windows-x86/Reazi
TARGET = $(TARGETDIR)/Reazi.dll
OBJDIR = ../bin-int/Release-windows-x86/Reazi
DEFINES += -DRZ_PLATFORM_WINDOWS -DRZ_BUILD_DLL -D_WINDLL -DRZ_RELEASE
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2 /MD
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2 -std=c++17 /MD
LIBS += vendor/GLFW/bin/Release-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Release-windows-x86/Glad/Glad.lib vendor/imgui/bin/Release-windows-x86/ImGui/ImGui.lib -lopengl32.lib
LDDEPS += vendor/GLFW/bin/Release-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Release-windows-x86/Glad/Glad.lib vendor/imgui/bin/Release-windows-x86/ImGui/ImGui.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -m32 -shared -Wl,--out-implib="../bin/Release-windows-x86/Reazi/Reazi.lib" -s
define POSTBUILDCMDS
	@echo Running postbuild commands
	IF EXIST ..\bin\Release-windows-x86\Reazi\Reazi.dll\ (xcopy /Q /E /Y /I ..\bin\Release-windows-x86\Reazi\Reazi.dll ..\bin\Release-windows-x86\Sandbox > nul) ELSE (xcopy /Q /Y /I ..\bin\Release-windows-x86\Reazi\Reazi.dll ..\bin\Release-windows-x86\Sandbox > nul)
endef

else ifeq ($(config),dist)
TARGETDIR = ../bin/Dist-windows-x86/Reazi
TARGET = $(TARGETDIR)/Reazi.dll
OBJDIR = ../bin-int/Dist-windows-x86/Reazi
DEFINES += -DRZ_PLATFORM_WINDOWS -DRZ_BUILD_DLL -D_WINDLL -DRZ_DISTG
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2 /MD
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2 -std=c++17 /MD
LIBS += vendor/GLFW/bin/Dist-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Dist-windows-x86/Glad/Glad.lib vendor/imgui/bin/Dist-windows-x86/ImGui/ImGui.lib -lopengl32.lib
LDDEPS += vendor/GLFW/bin/Dist-windows-x86/GLFW/GLFW.lib vendor/Glad/bin/Dist-windows-x86/Glad/Glad.lib vendor/imgui/bin/Dist-windows-x86/ImGui/ImGui.lib
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -m32 -shared -Wl,--out-implib="../bin/Dist-windows-x86/Reazi/Reazi.lib" -s
define POSTBUILDCMDS
	@echo Running postbuild commands
	IF EXIST ..\bin\Dist-windows-x86\Reazi\Reazi.dll\ (xcopy /Q /E /Y /I ..\bin\Dist-windows-x86\Reazi\Reazi.dll ..\bin\Dist-windows-x86\Sandbox > nul) ELSE (xcopy /Q /Y /I ..\bin\Dist-windows-x86\Reazi\Reazi.dll ..\bin\Dist-windows-x86\Sandbox > nul)
endef

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/Application.o
GENERATED += $(OBJDIR)/ImGuiLayer.o
GENERATED += $(OBJDIR)/ImGuiOpenGLRenderer.o
GENERATED += $(OBJDIR)/Layer.o
GENERATED += $(OBJDIR)/LayerStack.o
GENERATED += $(OBJDIR)/Log.o
GENERATED += $(OBJDIR)/WindowsWindow.o
GENERATED += $(OBJDIR)/rzpch.o
OBJECTS += $(OBJDIR)/Application.o
OBJECTS += $(OBJDIR)/ImGuiLayer.o
OBJECTS += $(OBJDIR)/ImGuiOpenGLRenderer.o
OBJECTS += $(OBJDIR)/Layer.o
OBJECTS += $(OBJDIR)/LayerStack.o
OBJECTS += $(OBJDIR)/Log.o
OBJECTS += $(OBJDIR)/WindowsWindow.o
OBJECTS += $(OBJDIR)/rzpch.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking Reazi
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning Reazi
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) rmdir /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/ImGuiOpenGLRenderer.o: src/Platform/OpenGL/ImGuiOpenGLRenderer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/WindowsWindow.o: src/Platform/Windows/WindowsWindow.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Application.o: src/Reazi/Application.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ImGuiLayer.o: src/Reazi/ImGui/ImGuiLayer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Layer.o: src/Reazi/Layer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LayerStack.o: src/Reazi/LayerStack.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Log.o: src/Reazi/Log.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/rzpch.o: src/rzpch.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) -include $(PCH_PLACEHOLDER) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif