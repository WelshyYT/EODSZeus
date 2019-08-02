class CfgPatches
{
	class EODS_Zeus
	{
		units[] = {"EODS_Z_Base"};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Modules_F"};
	};
};

class CfgFactionClasses
{
		class NO_CATEGORY;

		class EODS_Zeus: NO_CATEGORY
		{
			displayName = "EODS Zeus";
		};
};

class CfgFunctions
{
    class EODS
    {
        class ZeusModules
        {
            file = "\EODS_Zeus\functions";
            class misc {};
        };
    };
};


class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit; // Default edit box (i.e., text input field)
			class Combo; // Default combo box (i.e., drop-down menu)
			class Checkbox; // Default checkbox (returned value is Bool)
			class CheckboxNumber; // Default checkbox (returned value is Number)
			class ModuleDescription; // Module description
			class Units; // Selection of units on which the module is applied
		};
		// Description base classes, for more information see below
		class ModuleDescription
		{
			class AnyBrain;
		};
	};

	class EODS_Z_Base: Module_F
	{
		scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
		scopeCurator = 2;
		displayName = "EODS_Test"; // Name displayed in the menu
		icon = "\myTag_addonName\data\-.paa"; // Map icon. Delete this entry to use the default icon
		category = "EODS_Zeus";

		// Name of function triggered once conditions are met
		function = "EODS_fnc_misc";
		// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		functionPriority = 1;
		// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isGlobal = 1;
		// 1 for module waiting until all synced triggers are activated
		isTriggerActivated = 1;
		// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isDisposable = 1;
		// // 1 to run init function in Eden Editor as well
		is3DEN = 1;

		// Menu displayed when the module is placed or double-clicked on by Zeus
		curatorInfoType = "-";
	};
};
