#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"

void AnimationHandler::update(const float dt)
{   
    //Don't update us current animation does not exist
    if(currentAnim >= this->animations.size() || currentAnim < 0) return;

    float duration = this->animations[currentAnim].duration;
        //Get duration of current animation (time it takes for the frame to process)
        //If animation takes t-seconds then stay on current frame from 0-t seconds
 

    /* Check if the animation has progessed to a new frame and if so
     * change to the next frame */
    if(int((t + dt) / duration) > int(t / duration))
    {
        /* Calculate the frame number */
        int frame = int((t + dt) / duration);

        /* Adjust for looping */
        frame %= this->animations[currentAnim].getLength();

        /* Set the sprite to the new frame */
        //Compute rectangle of texture that sprite should be showing
        sf::IntRect rect = this->frameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * this->currentAnim;
        this->bounds = rect;
    }

    /* Increment the time elapsed */
    this->t += dt;
    /* Adjust for looping */
    if(this->t > duration * this->animations[currentAnim].getLength())
    {
        this->t = 0.0f;
    }

    return;
}

void AnimationHandler::addAnim(Animation& anim)
{
    this->animations.push_back(anim);

    return;
}

void AnimationHandler::changeAnim(unsigned int animID) //force change
{
    /* Do not change the animation if the animation is currently active or
     * the new animation does not exist */
    if(this->currentAnim == animID || animID >= this->animations.size() ||
        animID < 0) return;

    /* Set the current animation */
    this->currentAnim = animID;
    /* Update the animation bounds */
    sf::IntRect rect = this->frameSize;
    rect.top = rect.height * animID;
    this->bounds = rect;
    this->t = 0.0;

    return;
}