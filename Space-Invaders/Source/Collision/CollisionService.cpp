#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collision\CollisionService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collision\ICollider.h"

namespace Collision
{
	CollisionService::CollisionService() { }

	CollisionService::~CollisionService() { }

	void CollisionService::Initialize() { }

	void CollisionService::Update()
	{
		ProcessCollision();
	}

	void CollisionService::ProcessCollision()
	{
		for (int i = 0; i < collider_list.size(); i++)
		{
			for (int j = i + 1; j < collider_list.size(); j++)
			{
				DoCollision(i, j);
			}
		}
	}

	void CollisionService::DoCollision(int index_i, int index_j)
	{
		if (collider_list[index_i]->GetCollisionState() == CollisionState::DISABLED ||
			collider_list[index_j]->GetCollisionState() == CollisionState::DISABLED) return;

		if (HasCollisionOccurred(index_i, index_j))
		{
			if (AreActiveColliders(index_i, index_j))
				collider_list[index_i]->OnCollision(collider_list[index_j]);

			if (AreActiveColliders(index_i, index_j))
				collider_list[index_j]->OnCollision(collider_list[index_i]);
		}
	}

	bool CollisionService::HasCollisionOccurred(int index_i, int index_j)
	{
		const sf::Sprite& collider_one_sprite = collider_list[index_i]->GetColliderSprite();
		const sf::Sprite& collider_two_sprite = collider_list[index_j]->GetColliderSprite();

		return collider_one_sprite.getGlobalBounds().intersects(collider_two_sprite.getGlobalBounds());
	}

	bool CollisionService::AreActiveColliders(int index_i, int index_j)
	{
		return (index_i < collider_list.size() && index_j < collider_list.size() &&
			collider_list[index_i] != nullptr && collider_list[index_j] != nullptr);
	}
	void CollisionService::AddCollider(ICollider* collider)
	{
		collider_list.push_back(collider);
	}

	void CollisionService::RemoveCollider(ICollider* collider)
	{
		collider_list.erase(std::remove(collider_list.begin(), collider_list.end(), collider), collider_list.end());
	}
}