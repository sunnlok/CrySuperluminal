#include "StdAfx.h"
#include "Superluminal.h"

static CSuperluminal* g_pSuperluminal = nullptr;

CSuperluminal::CSuperluminal()
{
	g_pSuperluminal = this;
}

CSuperluminal::~CSuperluminal()
{
	g_pSuperluminal = nullptr;
}

void CSuperluminal::Update()
{
	
}