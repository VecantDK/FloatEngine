#include "Object.h"

Object::Object()
{
	m_block = { 0,0 };
	m_angle = 0.0f;
	m_origin = { 0,0 };
	x = y = 0;
	_m_obj_name = "NONE";
	_m_obj_pro = OBJPRO.Normal;
	depth = 0;
	image_index = 0;
	sprite_index = new Texture[0];
}

Object::Object(const char* name, int pro)
{
	m_block = Size{ 0,0 };
	m_angle = 0.0f;
	x = y = 0;
	m_origin = { 0,0 };
	_m_obj_name = name;
	_m_obj_pro = pro;
	depth = 0;
	image_index = 0;
	sprite_index = new Texture[0];
}

Object::~Object()
{
	_m_obj_name.clear();
}

void Object::Draw_Block(Color col)
{
	DrawRectanglePro({ x,y,m_block.width,m_block.height }, { m_block.width * m_origin.x,m_block.height * m_origin.y }, m_angle, col);
}


bool Object::Is_Meeting(float _x, float _y, const Object* other)
{
	F_Rectangle a, b;
	a.width = m_block.width;
	a.height = m_block.height;
	a.x = _x;
	a.y = _y;
	a.angle = m_angle;
	a.rot_origin = m_origin;
	a.Shape_Set();
	b.width = other->m_block.width;
	b.height = other->m_block.height;
	b.x = other->x;
	b.y = other->y;
	b.angle = other->m_angle;
	b.rot_origin = other->m_origin;
	b.Shape_Set();

	return GJK_Collision(a, b);
}

void Object::Event_User(int index)
{
	switch (index) {
	case 0:
		break;
	case Collision_With:
		break;
	default:
		break;
	}
}

void Object::onEnter()
{
}

void Object::onUpdate()
{
}

void Object::onRenderBefore()
{
}

void Object::onRender()
{
}

void Object::onRenderNext()
{
}

void Object::onDestroy()
{
}