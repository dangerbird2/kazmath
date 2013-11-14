/*
Copyright (c) 2009, Luke Benstead, Carsten Haubold
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _KAZMATHXX_VEC3_H
#define _KAZMATHXX_VEC3_H

#include <kazmath/vec3.h>

namespace km
{
	class vec3 : public kmVec3
	{
		public:
			///< Constructors
			vec3(const kmScalar _x, const kmScalar _y, const kmScalar _z)
			{
                 x = _x;
                 y = _y;
                 z = _z;			
			}
			vec3()
			{
                 x = kmScalar(0.0);
                 y = kmScalar(0.0);
                 z = kmScalar(0.0);			
			}
			
			///< Returns the length of the vector
			const kmScalar length() const
			{
				return kmVec3Length(this);
			}
			
			///< Returns the square of the length of the vector
			const kmScalar lengthSq() const
			{
				return kmVec3LengthSq(this);
			}
			
			
			///< Returns the vector passed in set to unit length
			const vec3 normalize() const
			{
				vec3 result;
				kmVec3Normalize(&result,this);
				return result;
			}
			
			///< Transform the Vector
			const vec3 transform(const kmMat4& mat) const
			{
				vec3 result;
				kmVec3Transform(&result,this, &mat);
				return result;
			}

			///< Transforms a 3D vector by a given matrix, projecting the result back into w = 1.
			const vec3 transformCoord(const kmMat4& mat) const
			{
				vec3 result;
				kmVec3TransformCoord(&result,this, &mat);
				return result;
			}
			
			///< Transforms the vector ignoring the translation part
			const vec3 transformNormal(const kmMat4& mat) const
			{
				vec3 result;
				kmVec3TransformNormal(&result,this, &mat);
				return result;
			}
			
			///< The cross product returns a vector perpendicular to this and another vector
			const vec3 cross(const kmVec3& vec) const
			{
				vec3 result;
				kmVec3Cross(&result, this, &vec);
				return result;
			}
			
			const vec3 inverseTransform(const kmMat4& mat) const
			{
				vec3 result;
				kmVec3InverseTransform(&result,this, &mat);
				return result;
			}
			
			const vec3 inverseTransformNormal(const kmMat4& mat) const
			{
				vec3 result;
				kmVec3InverseTransformNormal(&result,this, &mat);
				return result;
			}

            inline const vec3 operator+=( const vec3& rhs )
            {
                kmVec3Add( this, this, &rhs);
                return *this;
            }

            inline const vec3 operator+=( kmScalar rhs )
            {
                kmVec3Add( this, this, vec3( rhs, rhs ) );
                return *this;
            }

            inline const vec3 operator-=( const vec3& rhs )
            {
                kmVec3Subtract( this, this, &rhs);
                return *this;
            }

            inline const vec3 operator-=( kmScalar rhs )
            {
                kmVec3Subtract( this, this, vec3( rhs, rhs, rhs ) );
                return *this;
            }

            inline const vec3 operator*=( const vec3& rhs )
            {
                this->x *= rhs->x;
                this->y *= rhs->y;
                this->z *= rhs->z;
                return *this;
            }

            inline const vec3 operator*=( kmScalar rhs  )
            {
                this->x *= rhs;
                this->y *= rhs;
                this->z *= rhs;
                return *this;
            }

            inline const vec3 operator/=( const vec3& rhs )
            {
                this->x /= rhs->x;
                this->y /= rhs->y;
                this->z /= rhs->z;
                return *this;
            }

            inline const vec3 operator/=( kmScalar rhs  )
            {
                this->x /= rhs;
                this->y /= rhs;
                this->z /= rhs;
                return *this;
            }

            inline kmScalar dot( const vec3& rhs )
            {
                return kmVec3Dot(this, &rhs);
            }
	};
	
	///< Vector addition
	inline const vec3 operator+(const vec3& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Add(&result, &lhs, &rhs);
		return result;
    }

	///< Vector subtraction
	inline const vec3 operator-(const vec3& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Subtract(&result, &lhs, &rhs);
		return result;
    }
	
	///< Dot product - which is the cosine of the angle between the two vectors multiplied by their lengths
	inline const float operator*(const vec3& lhs, const vec3& rhs)
	{
		return kmVec3Dot(&lhs, &rhs);
    }
	
	///< Multiply with scalar
	inline const vec3 operator*(const kmScalar lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Scale(&result, &rhs, lhs);
		return result;
    }

	///< Multiply with scalar	
	inline const vec3 operator*(const vec3& lhs, const kmScalar rhs)
	{
		vec3 result;
		kmVec3Scale(&result, &lhs, rhs);
		return result;
    }
	
	///< Transform through matrix	
	inline const vec3 operator*(const kmMat4& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Transform(&result, &rhs, &lhs);
		return result;
    }
	
	///< Checks for equality (with a small threshold epsilon)
	inline const bool operator==(const vec3& lhs, const vec3& rhs)
	{
		return (kmVec3AreEqual(&lhs,&rhs) != 0);
    }
} //end of namespace km

#endif

