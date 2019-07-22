/*
 * Copyright (c) 2019 Kevin Townsend (KTOWN)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include <zsl/zsl.h>
#include <zsl/matrices.h>
#include <zsl/vectors.h>
#include <zsl/physics/atomic.h>
#include "floatcheck.h"

void test_phy_atom_nucl_radius(void)
{
	int rc;
	zsl_real_t r;

	rc = zsl_phy_atom_nucl_radius(5.0, &r);
	zassert_true(rc == 0, NULL);
	zassert_true(val_is_equal(r, 2.137469933E-15, 1E-6), NULL);

	/* Example for zero mass number. */
	rc = zsl_phy_atom_nucl_radius(0.0, &r);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(r != r, NULL);

	/* Example for negative mass number. */
	rc = zsl_phy_atom_nucl_radius(-3.0, &r);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(r != r, NULL);
}

void test_phy_atom_bohr_orb_radius(void)
{
	int rc;
	zsl_real_t r;

	rc = zsl_phy_atom_bohr_orb_radius(3.0, 5.0, &r);
	zassert_true(rc == 0, NULL);
	zassert_true(val_is_equal(r, 4.409810014E-10, 1E-6), NULL);

	/* Example for negative n. */
	rc = zsl_phy_atom_bohr_orb_radius(3.0, -5.0, &r);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(r != r, NULL);

	/* Example for negative Z. */
	rc = zsl_phy_atom_bohr_orb_radius(-3.0, 5.0, &r);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(r != r, NULL);
}

void test_phy_atom_bohr_orb_vel(void)
{
	int rc;
	zsl_real_t v;

	rc = zsl_phy_atom_bohr_orb_vel(3.0, 5.0, &v);
	zassert_true(rc == 0, NULL);
	// TODO: Fix test value
	// zassert_true(val_is_equal(v, 8.192697057E24, 1E-6), NULL);

	/* Example for negative n. */
	rc = zsl_phy_atom_bohr_orb_vel(3.0, -5.0, &v);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(v != v, NULL);

	/* Example for negative Z. */
	rc = zsl_phy_atom_bohr_orb_vel(-3.0, 5.0, &v);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(v != v, NULL);
}

void test_phy_atom_bohr_orb_ener(void)
{
	int rc;
	zsl_real_t e;

	rc = zsl_phy_atom_bohr_orb_ener(3.0, 5.0, &e);
	zassert_true(rc == 0, NULL);
	zassert_true(val_is_equal(e, -7.980983164E-33, 1E-6), NULL);

	/* Example for negative n. */
	rc = zsl_phy_atom_bohr_orb_vel(3.0, -5.0, &e);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(e != e, NULL);

	/* Example for negative Z. */
	rc = zsl_phy_atom_bohr_orb_vel(-3.0, 5.0, &e);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(e != e, NULL);
}

void test_phy_atom_rad_decay(void)
{
	int rc;
	zsl_real_t qf;

	rc = zsl_phy_atom_rad_decay(10.0, 20.0, 3.0, &qf);
	zassert_true(rc == 0, NULL);
	zassert_true(val_is_equal(qf, 8.756510763E-26, 1E-6), NULL);

	/* Example for negative time. */
	rc = zsl_phy_atom_rad_decay(10.0, -20.0, 3.0, &qf);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(qf != qf, NULL);

	/* Example for negative lambda. */
	rc = zsl_phy_atom_rad_decay(10.0, 20.0, -3.0, &qf);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(qf != qf, NULL);
}

void test_phy_atom_bragg(void)
{
	int rc;
	zsl_real_t d;

	rc = zsl_phy_atom_bragg(3.0, 1.1, 500.0, &d);
	zassert_true(rc == 0, NULL);
	zassert_true(val_is_equal(d, 841.5549889, 1E-6), NULL);

	/* Example for negative sin(theta). */
	rc = zsl_phy_atom_bragg(3.0, 5.9, 500.0, &d);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(d != d, NULL);

	/* Example for zero sin(theta). */
	rc = zsl_phy_atom_bragg(3.0, 0.0, 500.0, &d);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(d != d, NULL);

	/* Example for negative lambda. */
	rc = zsl_phy_atom_bragg(3.0, 5.9, -500.0, &d);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(d != d, NULL);

	/* Example for negative n. */
	rc = zsl_phy_atom_bragg(-3.0, 5.9, 500.0, &d);
	zassert_true(rc == -EINVAL, NULL);
	/* IEEE standard states that x != x is true only for NAN values. */
	zassert_true(d != d, NULL);
}
