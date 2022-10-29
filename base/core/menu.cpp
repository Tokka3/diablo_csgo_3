#include "menu.h"

// used: global variables
#include "../global.h"
// used: config variables
#include "../core/variables.h"
// used: actions with config
#include "../core/config.h"
// used: configurations error logging
#include "../utilities/logging.h"
// used: render setup, etc
#include "../utilities/draw.h"
// used: engine, inputsystem, convar interfaces
#include "../core/interfaces.h"
// used: render visuals
#include "../features/visuals.h"
// used: skinchanger tab items map
#include "../features/skinchanger.h"
// used: inputtext() wrappers for c++ standard library (stl) type: std::string
#include "../../dependencies/imgui/cpp/imgui_stdlib.h"

#include "../dbl_gui.h"

const std::pair<const char*, std::uint32_t> arrColors[] =
{
	{ "[esp] box - enemies", Vars.colEspMainBoxEnemies },
	{ "[esp] box - enemies wall", Vars.colEspMainBoxEnemiesWall },
	{ "[esp] box - allies", Vars.colEspMainBoxAllies },
	{ "[esp] box - allies wall", Vars.colEspMainBoxAlliesWall },
	{ "[glow] enemies", Vars.colEspGlowEnemies },
	{ "[glow] enemies wall", Vars.colEspGlowEnemiesWall },
	{ "[glow] allies", Vars.colEspGlowAllies },
	{ "[glow] allies wall", Vars.colEspGlowAlliesWall },
	{ "[glow] weapons", Vars.colEspGlowWeapons },
	{ "[glow] grenades", Vars.colEspGlowGrenades },
	{ "[glow] bomb", Vars.colEspGlowBomb },
	{ "[glow] planted bomb", Vars.colEspGlowBombPlanted },
	{ "[chams] enemies", Vars.colEspChamsEnemies },
	{ "[chams] enemies wall", Vars.colEspChamsEnemiesWall },
	{ "[chams] allies", Vars.colEspChamsAllies },
	{ "[chams] allies wall", Vars.colEspChamsAlliesWall },
	{ "[chams] viewmodel", Vars.colEspChamsViewModel },
	{ "[chams] viewmodel additional", Vars.colEspChamsViewModelAdditional },
	{ "[screen] hitmarker - lines", Vars.colScreenHitMarker },
	{ "[screen] hitmarker - damage", Vars.colScreenHitMarkerDamage }
};

#pragma region menu_array_entries
static constexpr std::array<std::string_view, 4U> arrVisualsFlags =
{
	"helmet",
	"kevlar",
	"defuse kit",
	"zoom"
};

static constexpr std::array<std::string_view, 4U> arrVisualsRemovals =
{
	"post-processing",
	"punch",
	"smoke",
	"scope"
};
#pragma endregion

// spectator list, radar, other stuff here
#pragma region menu_windows
dbl* db;

enum MV {
	HOME = 0,
	MAIN = 1,
	VISUALS = 2,
	SKINCHANGER = 3,
	SETTINGS = 4,
};

void W::MainWindow(IDirect3DDevice9* pDevice)
{

	static bool once = true;

	if (once) {
		db->LoadImages(pDevice);
		once = false;
	}
	ImGuiIO& io = ImGui::GetIO();
	const ImVec2 vecScreenSize = io.DisplaySize;

	ImGuiStyle& style = ImGui::GetStyle();
	ImDrawList* pForegroundDrawList = ImGui::GetForegroundDrawList();



	ImDrawList* pBackgroundDrawList = ImGui::GetBackgroundDrawList();
	
	D::RenderDrawData(pBackgroundDrawList);

	db->BackGround(bMainOpened);
	#pragma endregion

	#pragma region main_window
	io.MouseDrawCursor = bMainOpened;
	static bool wp = true;
	if (wp) {
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);

	
		ImGui::SetNextWindowPos(ImVec2(width / 2 - 380, height / 2 - 296));
		wp = false;
	}
	int navID = db->getNav();
	int categoryActiveID = db->getCat();
	if (bMainOpened || !db->CanCloseMenu())
	{
		int x, y;
		I::InputSystem->GetCursorPosition(&x, &y);

		// set imgui mouse position
		io.MousePos = ImVec2(static_cast<float>(x), static_cast<float>(y));
		
		ImGui::SetNextWindowPos(ImVec2(vecScreenSize.x * 0.5f, vecScreenSize.y * 0.5f), ImGuiCond_Once, ImVec2(0.5f, 0.5f));
		ImGui::SetNextWindowSize(ImVec2(758, 592), ImGuiCond_Always);
	

		db->Begin();
		if (navID == MV::VISUALS) {
			static int testSlider = 50;
			if (categoryActiveID == 0) {
				db->ChildBackGround(1, 572);
				db->DrawCheckBox(C::Get<bool>(Vars.bEspMainEnemies), "Enable ESP");
				db->Separator();
				db->DrawSliderInt(testSlider, 0, 100, "Test Slider");
	
				db->DrawMultiPicker(C::Get<bool>(Vars.bBox), C::Get<Color2>(Vars.cBoxColour).visible, C::Get<Color2>(Vars.cBoxColour).notVisible, C::Get<Color2>(Vars.cBoxColour).visible, "Box");
				db->DrawDropDown(C::Get<int>(Vars.iEspMainPlayerBox), { "Full", "Corners" }, "Box Type");

				db->DrawMultiPicker(C::Get<bool>(Vars.bFill), C::Get<Color2>(Vars.cFillColour).visible, C::Get<Color2>(Vars.cFillColour).notVisible, C::Get<Color2>(Vars.cFillColour).visible, "Fill");
				db->DrawMultiPicker(C::Get<bool>(Vars.bOutline), C::Get<Color2>(Vars.cOutlineColour).visible, C::Get<Color2>(Vars.cOutlineColour).notVisible, C::Get<Color2>(Vars.cBoxColour).visible, "Outline");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bSkeleton), C::Get<Color2>(Vars.cSkeletonColour).visible, C::Get<Color2>(Vars.cSkeletonColour).notVisible, C::Get<Color2>(Vars.cSkeletonColour).visible, "Skeleton");
				db->DrawSliderInt(C::Get<int>(Vars.iSkeletonThickness), 1, 6, "Thickness");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bHealthbar), C::Get<Color2>(Vars.cHealthBarColour).visible, C::Get<Color2>(Vars.cHealthBarColour).notVisible, C::Get<Color2>(Vars.cHealthBarColour).visible, "Health Bar");
				db->DrawMultiPicker(C::Get<bool>(Vars.bAmmoBar), C::Get<Color2>(Vars.cAmmoBarColour).visible, C::Get<Color2>(Vars.cAmmoBarColour).notVisible, C::Get<Color2>(Vars.cAmmoBarColour).visible, "Ammo Bar");
				db->DrawMultiPicker(C::Get<bool>(Vars.bArmorBar), C::Get<Color2>(Vars.cArmorBarColour).visible, C::Get<Color2>(Vars.cArmorBarColour).notVisible, C::Get<Color2>(Vars.cArmorBarColour).visible, "Armor Bar");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bName), C::Get<Color2>(Vars.colEspName).visible, C::Get<Color2>(Vars.colEspName).notVisible, C::Get<Color2>(Vars.colEspName).visible, "Name");
				db->DrawMultiPicker(C::Get<bool>(Vars.bWeapon), C::Get<Color2>(Vars.cWeaponColour).visible, C::Get<Color2>(Vars.cWeaponColour).notVisible, C::Get<Color2>(Vars.cWeaponColour).visible, "Weapon");
				db->DrawMultiPicker(C::Get<bool>(Vars.bHealth), C::Get<Color2>(Vars.cHealthColour).visible, C::Get<Color2>(Vars.cHealthColour).notVisible, C::Get<Color2>(Vars.cBoxColour).visible, "Health");
				db->DrawMultiPicker(C::Get<bool>(Vars.bAmmo), C::Get<Color2>(Vars.cAmmoColour).visible, C::Get<Color2>(Vars.cAmmoColour).notVisible, C::Get<Color2>(Vars.cBoxColour).visible, "Ammo");
				db->DrawMultiPicker(C::Get<bool>(Vars.bDistance), C::Get<Color2>(Vars.cDistanceColour).visible, C::Get<Color2>(Vars.cDistanceColour).notVisible, C::Get<Color2>(Vars.cBoxColour).visible, "Distance");
				db->Separator();
				db->ChildBackGround(2, 572);
			}

			if (categoryActiveID == 1) {
				db->ChildBackGround(1, 572);
				db->DrawCheckBox(C::Get<bool>(Vars.bEspMainAllies), "Enable ESP");
				db->Separator();


				db->DrawMultiPicker(C::Get<bool>(Vars.bBoxA), C::Get<Color2>(Vars.cBoxColourA).visible, C::Get<Color2>(Vars.cBoxColourA).notVisible, C::Get<Color2>(Vars.cBoxColourA).visible, "Box");
				db->DrawDropDown(C::Get<int>(Vars.iEspMainPlayerBox), { "Full", "Corners" }, "Box Type");

				db->DrawMultiPicker(C::Get<bool>(Vars.bFillA), C::Get<Color2>(Vars.cFillColourA).visible, C::Get<Color2>(Vars.cFillColourA).notVisible, C::Get<Color2>(Vars.cFillColourA).visible, "Fill");
				db->DrawMultiPicker(C::Get<bool>(Vars.bOutlineA), C::Get<Color2>(Vars.cOutlineColourA).visible, C::Get<Color2>(Vars.cOutlineColourA).notVisible, C::Get<Color2>(Vars.cBoxColourA).visible, "Outline");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bSkeletonA), C::Get<Color2>(Vars.cSkeletonColourA).visible, C::Get<Color2>(Vars.cSkeletonColourA).notVisible, C::Get<Color2>(Vars.cSkeletonColourA).visible, "Skeleton");
				db->DrawSliderInt(C::Get<int>(Vars.iSkeletonThicknessA), 1, 6, "Thickness ");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bHealthbarA), C::Get<Color2>(Vars.cHealthBarColourA).visible, C::Get<Color2>(Vars.cHealthBarColourA).notVisible, C::Get<Color2>(Vars.cHealthBarColourA).visible, "Health Bar");
				db->DrawMultiPicker(C::Get<bool>(Vars.bAmmoBarA), C::Get<Color2>(Vars.cAmmoBarColourA).visible, C::Get<Color2>(Vars.cAmmoBarColourA).notVisible, C::Get<Color2>(Vars.cAmmoBarColourA).visible, "Ammo Bar");
				db->DrawMultiPicker(C::Get<bool>(Vars.bArmorBarA), C::Get<Color2>(Vars.cArmorBarColourA).visible, C::Get<Color2>(Vars.cArmorBarColourA).notVisible, C::Get<Color2>(Vars.cArmorBarColourA).visible, "Armor Bar");
				db->Separator();
				db->DrawMultiPicker(C::Get<bool>(Vars.bNameA), C::Get<Color2>(Vars.colEspNameA).visible, C::Get<Color2>(Vars.colEspNameA).notVisible, C::Get<Color2>(Vars.colEspNameA).visible, "Name");
				db->DrawMultiPicker(C::Get<bool>(Vars.bWeaponA), C::Get<Color2>(Vars.cWeaponColourA).visible, C::Get<Color2>(Vars.cWeaponColourA).notVisible, C::Get<Color2>(Vars.cWeaponColourA).visible, "Weapon");
				db->DrawMultiPicker(C::Get<bool>(Vars.bHealthA), C::Get<Color2>(Vars.cHealthColourA).visible, C::Get<Color2>(Vars.cHealthColourA).notVisible, C::Get<Color2>(Vars.cBoxColourA).visible, "Health");
				db->DrawMultiPicker(C::Get<bool>(Vars.bAmmoA), C::Get<Color2>(Vars.cAmmoColourA).visible, C::Get<Color2>(Vars.cAmmoColourA).notVisible, C::Get<Color2>(Vars.cBoxColourA).visible, "Ammo");
				db->DrawMultiPicker(C::Get<bool>(Vars.bDistanceA), C::Get<Color2>(Vars.cDistanceColourA).visible, C::Get<Color2>(Vars.cDistanceColourA).notVisible, C::Get<Color2>(Vars.cBoxColourA).visible, "Distance");
				db->Separator();
				db->ChildBackGround(2, 572);
			}
		}	
		db->End();
		db->CleanUp();
		db->InputListener();

	
	}
	#pragma endregion
}
#pragma endregion

