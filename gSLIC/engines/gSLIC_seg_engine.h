#pragma once
#include "../gSLIC_defines.h"
#include "../objects/gSLIC_settings.h"
#include "../objects/gSLIC_spixel_info.h"

namespace gSLIC
{
	namespace engines
	{
		class seg_engine
		{
		protected:

			// images
			UChar4Image *source_img;
			Float4Image *cvt_img;
			IntImage *idx_img;

			// superpixel map
			SpixelMap* spixel_map;
			int spixel_size;

			bool has_segmented;
			bool has_img_loaded;

			objects::settings gslic_settings;



			virtual void Cvt_Img_Space(UChar4Image* inimg, Float4Image* outimg, COLOR_SPACE color_space) = 0;
			virtual void Init_Cluster_Centers() = 0;
			virtual void Find_Center_Association() = 0;
			virtual void Update_Cluster_Center() = 0;
			virtual void Enforce_Connectivity();

		public:

			seg_engine(const objects::settings& in_settings );
			virtual ~seg_engine();

			const IntImage* Get_Seg_Mask() const {
				if (has_segmented) return idx_img;
				else return NULL;
			};

			void Perform_Segmentation(UChar4Image* in_img);
			virtual void Draw_Segmentation_Result(UChar4Image* out_img){};
		};
	}
}
