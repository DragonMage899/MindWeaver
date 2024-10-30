#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    //Provide Animation support to sprites
    //AnimationHandler included as a member to sprites needed animation
    //Each sprite has it's own texture file that contains stages for thee animation
    //Texture file will be split into a grid
    // animationframes moving rightward (of the same animation) and different animation extend down 

    public:

    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration) //duration : time(s) for 1 frame. start and end are 0 based indices in the texture grid
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }

    unsigned int getLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler
{
    private:

    /* Array of animations */
    std::vector<Animation> animations;
        //Each index denotes the location of one of the animations (animations then run rightwards)

    /* Current time since the animation loop started */
    float t; //use to determine when next frame should occur

    int currentAnim; //Vertical index of texture grid
    //index for our animations vector

    public:

    /* Add a new animation */
    void addAnim(Animation& anim);

    /* Update the current frame of animation. dt is the time since
     * the update was last called (i.e. the time for one frame to be
     * executed) */
    void update(const float dt);

    /* Change the animation, resetting t in the process */
    void changeAnim(unsigned int animNum);

    /* Current section of the texture that should be displayed */
    sf::IntRect bounds; //Int Rectangle
    //Tells us which section of the texture sprite to show

    /* Pixel dimensions of each individual frame */
    sf::IntRect frameSize;

    /* Constructor */
    AnimationHandler()
    {
        this->t = 0.0f;
        this->currentAnim = -1;
    }
    AnimationHandler(const sf::IntRect& frameSize)
    {
        this->frameSize = frameSize;

        this->t = 0.0f;
        this->currentAnim = -1;
    }
};

#endif