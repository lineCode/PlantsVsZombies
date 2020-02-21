/**
 *Copyright (c) 2019 LZ.All Right Reserved
 *Author : LZ
 *Date: 2019.7.1
 *Email: 2117610943@qq.com
 */

#include "HelpScene.h"
#include "Scenes/MainMenuScene/MainMenu.h"
#include "ui/CocosGUI.h"
#include "Scenes/EasterEggsScene/GameEasterEggs.h"

Scene* HelpScene::createHelpScene()
{
	return HelpScene::create();
}

bool HelpScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	AudioEngine::setVolume(AudioEngine::play2d(_global->userInformation->getMusicPath().find("paper")->second), _global->userInformation->getSoundEffectVolume());

	/* 获取窗口大小 */
	auto const size=Director::getInstance()->getWinSize();

	/* 创建背景 */
	auto sprite = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey(_global->userInformation->getImagePath().find("WorldBackground")->second));
	sprite->setPosition(size / 2);
	this->addChild(sprite);

	auto rotate = Sprite::create(_global->userInformation->getImagePath().find("RunBackground")->second);
	rotate->setScale(3.5f);
	rotate->setPosition(size / 2);
	this->addChild(rotate);
	rotate->runAction(RepeatForever::create(RotateBy::create(1.0f, -10)));

	auto WorldBackgroundBlack = Sprite::create(_global->userInformation->getImagePath().find("WorldBackgroundBlack")->second);
	auto WorldBackgroundBlack1 = Sprite::create(_global->userInformation->getImagePath().find("WorldBackgroundBlack")->second);
	WorldBackgroundBlack->setAnchorPoint(Vec2(0, 1));
	WorldBackgroundBlack->setPosition(Vec2(0, 1140));
	WorldBackgroundBlack1->setAnchorPoint(Vec2(0, 0));
	WorldBackgroundBlack1->setPosition(Vec2(0, -60));
	WorldBackgroundBlack1->setFlippedY(true);
	this->addChild(WorldBackgroundBlack);
	this->addChild(WorldBackgroundBlack1);

	/* 创建文字背景 */
	auto note = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey(_global->userInformation->getImagePath().find("ZombieNote")->second));
	note->setScale(1.7f);
	note->setScaleX(2.2f);
	note->setPosition(Vec2(size.width / 2 + 60, size.height / 2));
	this->addChild(note);

	auto helptext = Label::createWithTTF("\
        此游戏全部由本人自己制作完成。此版本为测试版(具有一定的可玩性)，今后会不定时更新（不断完善）。待游戏完成后，\
我将会把所有源码开源发到GitHub。在此感谢大家的关注！\n        游戏大部分的素材来源于原版游戏素材，少部分搜集于网络，以及自己制作。\n\
        此游戏为同人游戏而且仅供学习交流使用，任何人未经授权，不得对本游戏进行更改、盗用等，否则后果自负。\n\
        目前有六种僵尸和九种植物，植物和僵尸的动画都是本人做的，由于做动画的能力有限，有些僵尸和植物动画不能实现，\
如果可以做动画并且愿意帮助我的人可以私聊我（动画是用spine软件制作的骨骼动画）。如果发现程序有什么问题或者对游戏有\
什么建议可以发送到我的qq：2117610943", "resources/fonts/fzse_gbk.ttf", 35);

	helptext->setPosition(size / 2.0f);
	helptext->setColor(Color3B::BLACK);
	helptext->setMaxLineWidth(900);
	this->addChild(helptext);

	/* 创建按钮 */
	auto button = Button::create(_global->userInformation->getImagePath().find("SeedChooser_Button2")->second, _global->userInformation->getImagePath().find("SeedChooser_Button2_Glow")->second);
	button->setTitleText(_global->userInformation->getGameText().find("主菜单")->second);
	button->setTitleColor(Color3B(0,255,255));
	button->setTitleFontSize(18);
    button->setScale(2.0f);
	button->setPosition(Vec2(size.width / 2, 100));
	this->addChild(button);
	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case Widget::TouchEventType::BEGAN:
			AudioEngine::setVolume(AudioEngine::play2d(_global->userInformation->getMusicPath().find("tap2")->second), _global->userInformation->getSoundEffectVolume());
			break;
		case Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(MainMenu::createScene());
			break;
		}
	});

	return true;
}
