#pragma once

#include <SFML/Graphics.hpp>

#include "animation.hpp"

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
    public:
        explicit AnimatedSprite(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);

        void update(sf::Time deltaTime);
        void setAnimation(const Animation& animation);
        void setFrameTime(sf::Time time);
        
        void play();
        void play(const Animation& animation);
        void pause();
        void stop();

        void setLooped(bool looped);
        void setColour(const sf::Color& colour);
        
        const Animation* getAnimation() const;
        sf::FloatRect getLocalBounds() const;
        sf::FloatRect getGlobalBounds() const;
        bool isLooped() const;
        bool isPlaying() const;
        sf::Time getFrameTime() const;

        void setFrame(std::size_t newFrame, bool resetTime = true);

    private:
        const Animation* animation;
        sf::Time frameTime;
        sf::Time currentTime;
        std::size_t currentFrame;
        bool paused;
        bool looped;
        const sf::Texture* texture;
        sf::Vertex vertices[4];

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};