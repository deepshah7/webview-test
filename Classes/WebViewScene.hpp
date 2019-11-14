//
//  WebViewScene.hpp
//  webview-test
//
//  Created by Deep Shah on 14/11/19.
//

#ifndef WebViewScene_hpp
#define WebViewScene_hpp

#include <stdio.h>
#include "cocos2d.h"


class WebViewScene : public cocos2d::Node {

public:

// returns a CCScene that contains the Login as the only child
    static cocos2d::Scene *  scene();

    CREATE_FUNC(WebViewScene);
public:

    virtual void onEnter();
    virtual void onExit();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
};


#endif /* WebViewScene_hpp */
