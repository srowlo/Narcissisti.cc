#pragma once

namespace SSDK {
	class C_TEFireBullets
	{
	public:
		char pad[12];
		int		m_iPlayer; //12
		int _m_iItemDefinitionIndex;
		Vector	_m_vecOrigin;
		Vector	m_vecAngles;
		int		_m_iWeaponID;
		int		m_iMode;
		int		m_iSeed;
		float	m_flSpread;
	};
}
