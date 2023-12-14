[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# Which Witch Will Win

## Project Info
A local-mutltiplayer fighting game with support for animated spritesheets.

## Patterns used
- [Command](#command)
- [Observer](#observer)
- [Component](#component)
- [Game Loop](#game-loop-and-update-method)
- [Update Method](#game-loop-and-update-method)

### Command
- What does it do?
  - Input Handling
- Why was it chosen?
  - Easy to have [different](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/GameObjects/CommandManager.cpp#L12) input-schemes for the players
  - Easy to add more inputs with more Commands
- How was it implemented?
  - [Base Command](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/input.h#L13) class with a virtual Execute method
  - InputHandler instance which [returns](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/input.cpp#L39) a list of Commands
  - CommandManager [executes](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/0623047e16334e978ed0fc57f429e04cea68318e/GameEngine/GameObjects/CommandManager.cpp#L20) the list Commands on the players

### Observer
- What does it do?
  - Animation
- Why was it chosen?
  - Enabled decoupling of the animation system from the Player component
- How was it implemented?
  - A base [Subject](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/main/GameEngine/Events/Subject.h) and [Observer](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/main/GameEngine/Events/Observer.h) class
  - Player [Notifies](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/995d408cc38e229e5344494855a8e99111bceacc/GameEngine/GameObjects/Player.cpp#L160) its Observers (the [Animator Component](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/main/GameEngine/Animator.h) ) with an Event
  - The Animator [plays](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/blob/995d408cc38e229e5344494855a8e99111bceacc/GameEngine/Animator.cpp#L138) an Animation based on the Event type

### Component
- What does it do?
- Why was it chosen?
- How was it implemented?

### Game Loop and Update Method
- What does it do?
- Why was it chosen?
- How was it implemented?

### Media

https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/assets/57400375/d48cd56b-08f0-493f-b9c6-f2fdca1d6157
![Screenshot 2023-12-14 134445](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/assets/57400375/c8d58702-0502-4c91-bc66-4e262f2c7a7a)
![Screenshot 2023-12-14 134643](https://github.com/FG22-GP/214-design-patterns-assignment-mj-me-ak/assets/57400375/9f6dbc71-ad83-4c3c-98f2-57fb0dfa23b9)


