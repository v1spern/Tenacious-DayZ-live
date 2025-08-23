void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{	
void SetRandomHealth(EntityAI itemEnt)
{
	int rndHlt = Math.RandomInt(60,100);
	itemEnt.SetHealth("","",rndHlt);
}

override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
{
	Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
	Class.CastTo(m_player, playerEnt);
	GetGame().SelectPlayer(identity, m_player);

	return m_player;
}

override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
{
	player.RemoveAllItems();

	EntityAI itemEnt;
	ItemBase itemBs;
	float rand;

	switch (Math.RandomInt(0, 9)) { 
			case 0:
	// Soldier
	player.GetInventory().CreateInInventory("TTSKOPants");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("TShirt_Green");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("CombatBoots_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AviatorGlasses");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("CombatKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break;
			case 1: 
	// Paramedic 
	player.GetInventory().CreateInInventory("ParamedicPants_Green");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("ParamedicJacket_Green");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("MedicalScrubsHat_Green");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SurgicalGloves_Green");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Green");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Uncuepa_SurgicalMask_blood");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("ThinFramesGlasses");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("AMS_WaterStraw");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);
	
	break; 
			case 2: 
	// Office worker
	player.GetInventory().CreateInInventory("SlacksPants_Black");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("Uncuepa_Shirt_PlainWhite");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("DressShoes_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Paper");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Pen_Blue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("ThinFramesGlasses");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("KitchenKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 3: 
	// Biker
	player.GetInventory().CreateInInventory("Uncuepa_Jeans_Wounded");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Uncuepa_RidersJacket_BlackWhite");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AviatorGlasses");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("WorkingBoots_Grey");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("Pipe");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 4: 
	// Hiker
	player.GetInventory().CreateInInventory("Uncuepa_HikingJacket_blackblue");itemBs = ItemBase.Cast(itemEnt); 
	player.GetInventory().CreateInInventory("Uncuepa_CargoPants_Flecktarn");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Uncuepa_HikingBoots_white");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Compass");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("WaterBottle");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 5: 
	// Skater
	player.GetInventory().CreateInInventory("Layered_Shirt_Courage");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Kneepads_Jeans_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SK8_Sneakers_Black");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("BoneKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 6: 
	// Lumberjack
	player.GetInventory().CreateInInventory("Shirt_RedCheck");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Jeans_Blue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("WorkingBoots_Brown");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("Hatchet");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 7: 
	// Hood 
	player.GetInventory().CreateInInventory("TrackSuitPants_LightBlue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("TrackSuitJacket_LightBlue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Uncuepa_BaseballCap_blackblue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("AthleticShoes_Black");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("KitchenKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break; 
			case 8: 
	// Islander
	player.GetInventory().CreateInInventory("Uncuepa_Shirt_Hawaiian1");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("Uncuepa_Jeans_Acidwash");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("SportGlasses_Black");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("FlipFlops_Colorbase");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("SteakKnife");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);

	break;
			case 9: 
	// Roadworker
	player.GetInventory().CreateInInventory("Medium_Sleeves_Shirt_Blue");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("DAC_CargoPants_Tan");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("ReflexVest");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("ConstructionHelmet_Yellow");itemBs = ItemBase.Cast(itemEnt);
	player.GetInventory().CreateInInventory("WorkingBoots_Yellow");itemBs = ItemBase.Cast(itemEnt);
	itemEnt = player.GetInventory().CreateInInventory("PipeWrench");
		itemBs = ItemBase.Cast(itemEnt);
		player.SetQuickBarEntityShortcut(itemEnt, 0);
	
	break; 
	}
//   Give universal gear

	rand = Math.RandomFloatInclusive( 0.0, 1.0 );

		if ( rand > 0.80 ) // Check for the highest value first
		    itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Cola" );
		else if ( rand > 0.60 )
		    itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Pipsi" );
		else if ( rand > 0.40 )
		    itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Spite" );
		else if ( rand > 0.20 )
		    itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Kvass" );
		else // This covers everything from 0.0 to 0.20
		    itemEnt = player.GetInventory().CreateInInventory( "SodaCan_Fonta" );

	player.SetQuickBarEntityShortcut(itemEnt, 1);
	SetRandomHealth( itemEnt );

	itemEnt = player.GetInventory().CreateInInventory("BandageDressing");
		itemBs = ItemBase.Cast(itemEnt);
	player.SetQuickBarEntityShortcut(itemEnt, 2);
			SetRandomHealth( itemEnt );

	itemEnt = player.GetInventory().CreateInInventory("Matchbox");
	itemBs = ItemBase.Cast(itemEnt);
	itemBs.SetQuantity(2);

	rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "Apple" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "Pear" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "Plum" );
	player.SetQuickBarEntityShortcut(itemEnt, 3);
			SetRandomHealth( itemEnt );
	
	
//		SetRandomHealth(itemEnt);
//		player.GetInventory().CreateInInventory("HuntingKnife");
}
};
Mission CreateCustomMission(string path)
{
return new CustomMission();
}