/*!
 * @file AbstractRPGCharacter.h
 * @brief Interface of classes used to describe a RPG character.
 * @author SignC0dingDw@rf
 * @date 29 April 2018
 *
 * Definition of RPG-like characters that can earn experience and level up. Optionnally they can also lose experience and level down. <br>
 * The class proposes a default behavior for XP win or loss that implies that character can go several levels up or down. You may overload these methods to enforce different behavior. <br>
 * Abstract class.
 *
 */

#ifndef ABSTRACT_RPG_CHARACTER_H
#define ABSTRACT_RPG_CHARACTER_H

#include <stdint.h>

/*!
* @namespace ShadeEngine
* @brief A namespace used to regroup all classes associated with ShadeEngine library
*/
namespace ShadeEngine
{
    /*! \class AbstractRPGCharacter
    * \brief Class defining interface of RPG-like characters.
    *
    * Definition of a class used manage RPG-like characters' experience and levels. <br>
    * Abstract class.
    *
    */
    class AbstractRPGCharacter
    {
    public:
        /*!
        * @brief Constructor of the AbstractRPGCharacter class
        * @param level_max : Maximal level of character. Default is 100.
        * @param can_level_down : Flag used to indicate if character can loose XP and level down. Default is false.
        */
        AbstractRPGCharacter(uint8_t level_max=100, bool can_level_down = false);

        /*!
        * @brief Destructor of the AbstractRPGCharacter class
        *
        * Virtual method. Does nothing.
        *
        */
        virtual ~AbstractRPGCharacter() = default;

    public slots:
        /*!
        * @brief Gain experience points if not at level max and level up if enough XP has been gathered.
        * @param m_xp_gained : XP gained
        *
        * Make your character gain XP. If sufficient XP has been gathered, character may level up several times (caped by level max). <br>
        * Method is not final so you may redefine it to implement specific xp handling behavior. <br>
        * Virtual slot.
        *
        */
        virtual void gainXP(uint64_t m_xp_gained);

        /*!
        * @brief Loose experience points if not at level max and level up if enough XP has been gathered.
        * @param m_xp_lost : XP Lost
        *
        * Make your character loose XP. If sufficient XP has been lost, character may level down several times (caped by level 1). <br>
        * Method is not final so you may redefine it to implement specific xp handling behavior. <br>
        * Virtual slot.
        *
        */
        virtual void loseXP(uint64_t m_xp_lost);

    protected:
        uint8_t m_level; /*!< Current level of character (between 1 and m_level_max). */
        uint8_t m_level_max; /*!< Maximal character level. */
        bool m_can_level_down; /*!< Can character loose XP and level down ? */
        uint64_t m_xp; /*!< Current accumulated experience points. */

        /*!
        * @brief User specific level up actions
        *
        * Application specific operations performed when character levels up.
        * Level up is performed in gainXP function before calling this method so it should not be done in this method. <br>
        * Abstract method.
        *
        */
        virtual void onLevelUp() = 0;

        /*!
        * @brief User specific level down actions
        *
        * Application specific operations performed when character levels down.
        * Level down is performed in loseXP function before calling this method so it should not be done in this method. <br>
        * Abstract method.
        *
        */
        virtual void onLevelDown() = 0;

        /*!
        * @brief Get XP associated with level
        *
        * Get the amount of XP associated with a given level.
        * Level is reach when the characters gathers the exact number of XP returned by this function. <br>
        * Abstract method.
        *
        */
        virtual uint64_t getLevelXp(uint8_t m_level) const = 0;
    };
}

#endif

//  ______________________________
// |                              |
// |    ______________________    |
// |   |                      |   |
// |   |         Sign         |   |
// |   |        C0ding        |   |
// |   |        Dw@rf         |   |
// |   |         1.0          |   |
// |   |______________________|   |
// |                              |
// |______________________________|
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |  |
//               |__|
