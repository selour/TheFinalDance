#pragma once
class DelaySwitch
{
public:
	DelaySwitch();

	operator bool() const { return m_Switch; }
	operator float() const { return GetProportion(); }

	const float GeCurrentTime() const { return m_Time; }
	const float GetDelayTime() const { return m_DelayTime; }

	const float GetProportion() const { return m_Time / m_DelayTime; }
	bool IsEnd() const { return m_Switch && GetProportion() == 1.0f; };
	void SetDelay(float delayTime);
	void Clear();
	void Update(float ts);
	
private:
	bool m_Switch;
	float m_Time;
	float m_DelayTime;
};

