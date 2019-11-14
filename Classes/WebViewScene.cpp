//
//  WebViewScene.cpp
//  webview-test
//
//  Created by Deep Shah on 14/11/19.
//

#include "WebViewScene.hpp"
#include "HelloWorldScene.h"
#include <cocos/ui/UIWebView.h>
#include <cocos/ui/UIButton.h>

USING_NS_CC;


//Now we need to show the existing users in the system -- DEEP
// Helper class method that creates a Scene with the Login as the only child.
cocos2d::Scene *  WebViewScene::scene()
{
    // 'scene' is an autorelease object.
    cocos2d::Scene *scene = (cocos2d::Scene::create());

    // 'layer' is an autorelease object.
    WebViewScene *layer = (WebViewScene::create());
    (layer->setTag(8888)); // do not change this tag. It is used by

    // add layer as a child to scene
    (scene->addChild(layer));

    // return the scene
    return scene;
}

#define kWebViewSceneTag 100
#define kPrivacyHeaderTag 101

void  WebViewScene::onEnter() {
    Node::onEnter();
    
    auto szWin = Director::getInstance()->getWinSize();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = (ui::Button::create("CloseNormal.png", "CloseSelected.png", "", (ui::Widget::TextureResType::LOCAL)));
    (closeItem->addClickEventListener([this](cocos2d::Ref *sender) {
        this->menuCloseCallback(sender);
    }));
    (closeItem->setScale(((szWin.height)/7.5f)/ ((closeItem->getContentSize()).height)));
    (closeItem->setPosition(cocos2d::Vec2(((closeItem->getContentSize()).width)* (closeItem->getScale()), (0.95 * szWin.height))));
    this->addChild(closeItem, 1);

    cocos2d::experimental::ui::WebView *webView = cocos2d::experimental::ui::WebView::create();
    webView->loadURL("https://google.com");
    webView->setAnchorPoint(cocos2d::Vec2(0, 0));
    webView->setPosition(cocos2d::Vec2(0, 0));
    webView->setContentSize(Size(szWin.width, 0.9f*szWin.height));
    webView->setTag(kWebViewSceneTag);
    this->addChild(webView);
}

void  WebViewScene::onExit() {
    Node::onExit();
}


void WebViewScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
