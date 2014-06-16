/****************************************************************************
Copyright (c) 2012 cocos2d-x.org

http://www.cocos2d-x.org

Created by Jung Sang-Taik on 12. 3. 16..
Copyright (c) 2012 Neofect. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CAScale9ImageView_H__
#define __CAScale9ImageView_H__

#include "CAImageView.h"

NS_CC_BEGIN

/**
 * @addtogroup GUI
 * @{
 * @addtogroup control_extension
 * @{
 */

/**
 * A 9-slice sprite for cocos2d.
 *
 * 9-slice scaling allows you to specify how scaling is applied
 * to specific areas of a sprite. With 9-slice scaling (3x3 grid),
 * you can ensure that the sprite does not become distorted when
 * scaled.
 *
 * @see http://yannickloriot.com/library/ios/cccontrolextension/Classes/CAScale9ImageView.html
 */

class CC_DLL CAScale9ImageView : public CAView
{
public:
    
    static CAScale9ImageView* create();
    
    CAScale9ImageView();
    virtual ~CAScale9ImageView();

public:
    /** Original sprite's size. */
    CC_SYNTHESIZE_READONLY(CCSize, m_originalSize, OriginalSize);
    /** 
     * The end-cap insets. 
     * On a non-resizeable sprite, this property is set to CGRectZero; the sprite 
     * does not use end caps and the entire sprite is subject to stretching. 
     */
    CC_PROPERTY(CCRect, m_capInsets, CapInsets);
    /** Sets the left side inset */
    CC_PROPERTY(float, m_insetLeft, InsetLeft);
    /** Sets the top side inset */
    CC_PROPERTY(float, m_insetTop, InsetTop);
    /** Sets the right side inset */
    CC_PROPERTY(float, m_insetRight, InsetRight);
    /** Sets the bottom side inset */
    CC_PROPERTY(float, m_insetBottom, InsetBottom);
    
protected:
    bool m_bSpritesGenerated;
    CCRect m_spriteRect;
    CCRect m_capInsetsInternal;
    bool m_positionsAreDirty;
    
    CABatchView* _scale9Image;
    CAImageView* _topLeft;
    CAImageView* _top;
    CAImageView* _topRight;
    CAImageView* _left;
    CAImageView* _centre;
    CAImageView* _right;
    CAImageView* _bottomLeft;
    CAImageView* _bottom;
    CAImageView* _bottomRight;

    bool _opacityModifyRGB;
    GLubyte _opacity;
    CAColor4B _color;
    
    void updateCapInset();
    void updatePositions();

    virtual void setContentSize(const CCSize & size);
    
public:

    /**
     *  @js NA
     */
    
    virtual bool init();

    /**
     * Initializes a 9-slice sprite with a image file, a delimitation zone and
     * with the specified cap insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param file The name of the image file.
     * @param rect The rectangle that describes the sub-part of the image that
     * is the whole image. If the shape is the whole image, set this to the 
     * image's full rect.
     * @param capInsets The values to use for the cap insets.
     */

	virtual bool initWithImage(CAImage* image, CCRect rect, CCRect capInsets);

	static CAScale9ImageView* createWithImage(CAImage* image, CCRect rect, CCRect capInsets);

	virtual bool initWithImage(CAImage* image, CCRect rect);

	static CAScale9ImageView* createWithImage(CAImage* image, CCRect rect);

	virtual bool initWithImage(CCRect capInsets, CAImage* image);

	static CAScale9ImageView* createWithImage(CCRect capInsets, CAImage* image);

	virtual bool initWithImage(CAImage* image);

	static CAScale9ImageView* createWithImage(CAImage* image);

    /**
     * Creates and returns a new sprite object with the specified cap insets.
     * You use this method to add cap insets to a sprite or to change the existing
     * cap insets of a sprite. In both cases, you get back a new image and the 
     * original sprite remains untouched.
     *
     * @param capInsets The values to use for the cap insets.
     */
    CAScale9ImageView* resizableSpriteWithCapInsets(CCRect capInsets);
    
    virtual void setColor(const CAColor4B& color);
	virtual const CAColor4B& getColor();
    
    virtual void updateDisplayedColor(const cocos2d::CAColor4B& parentColor);
    virtual bool updateWithImage(CABatchView* batch, CCRect rect, CCRect capInsets);
};

// end of GUI group
/// @}
/// @}

NS_CC_END

#endif // __CAScale9ImageView_H__